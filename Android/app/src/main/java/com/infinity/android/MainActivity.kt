package com.infinity.android

import android.Manifest
import android.annotation.SuppressLint
import android.app.Activity
import android.bluetooth.*
import android.content.BroadcastReceiver
import android.content.Context
import android.content.Intent
import android.content.IntentFilter
import android.content.pm.PackageManager
import android.graphics.Color
import android.os.Build
import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import android.util.Log
import android.view.View
import android.widget.*
import androidx.activity.result.contract.ActivityResultContracts
import androidx.core.app.ActivityCompat
import androidx.core.content.ContextCompat.getSystemService
import androidx.core.content.getSystemService
import androidx.core.view.ViewCompat
import androidx.core.view.WindowInsetsCompat
import androidx.core.view.WindowInsetsControllerCompat
import io.github.controlwear.virtual.joystick.android.JoystickView
import com.infinity.android.Actions.*
import java.io.IOError
import java.util.*
import kotlin.math.log

class MainActivity : AppCompatActivity() {
    private var armJaw = true
    private var connected = false
    private lateinit var bAdapter: BluetoothAdapter
    private var bSocket:BluetoothSocket? = null
    private lateinit var bluetoothIcon: ImageView
    private lateinit var connectBluetooth:Button
    private lateinit var address:String
    private lateinit var pairedDevices:Set<BluetoothDevice>
    private val uuid = UUID.fromString("00001101-0000-1000-8000-00805F9B34FB")
    private val c = this

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)
        hideSystemBars()

        val speed:SeekBar = findViewById(R.id.speed)
        val arm:SeekBar = findViewById(R.id.arm)
        val armIcon:ImageView = findViewById(R.id.armIcon)
        val fire:ImageButton = findViewById(R.id.fire)
        val toggleArmJaw:ImageButton = findViewById(R.id.toggleArm)
        val toggleShowArm:Switch = findViewById(R.id.toggleShowArm)
        val move:JoystickView = findViewById(R.id.move)
        val rotateLeft:ImageButton = findViewById(R.id.rotate_left)
        val rotateRight:ImageButton = findViewById(R.id.rotate_right)

        connectBluetooth = findViewById(R.id.connectBluetooth)
        bluetoothIcon = findViewById(R.id.bluetoothIcon)

        bAdapter = (this.getSystemService(Context.BLUETOOTH_SERVICE) as BluetoothManager).adapter

        //Change Speed
        speed?.setOnSeekBarChangeListener(object : SeekBar.OnSeekBarChangeListener{
            override fun onProgressChanged(seek: SeekBar?, progress: Int, fromUser: Boolean) {
                val command = "m:$progress;"
                send(command)
            }
            override fun onStartTrackingTouch(seek: SeekBar?) {}
            override fun onStopTrackingTouch(seek: SeekBar?) {}
        })

        //Arm Movement
        arm?.setOnSeekBarChangeListener(object : SeekBar.OnSeekBarChangeListener{
            override fun onProgressChanged(seek: SeekBar?, progress: Int, fromUser: Boolean) {
                val command = "l:$progress;"
                send(command)
            }
            override fun onStartTrackingTouch(seek: SeekBar?) {}
            override fun onStopTrackingTouch(seek: SeekBar?) {}
        })

        //Fire
        fire.setOnClickListener{ send(FIRE) }

        //Rotate car to the left
        rotateLeft.setOnClickListener{ send(ROTATE_LEFT) }

        //Rotate car to the right
        rotateRight.setOnClickListener{ send(ROTATE_RIGHT) }

        //Open and close arm
        toggleArmJaw.setOnClickListener{
            send(if(armJaw) CLOSE_ARM else OPEN_ARM)
            toggleArmJaw.setColorFilter(if(armJaw) Color.rgb(204, 0, 0) else Color.rgb(0, 204, 0))
            armJaw = !armJaw
        }

        //Move car
        move.setOnMoveListener { angle, strength ->
            val moves = arrayListOf(MOVE_RIGHT, MOVE_FORWARD_RIGHT, MOVE_FORWARD, MOVE_FORWARD_LEFT, MOVE_LEFT, MOVE_BACKWARD_LEFT, MOVE_BACKWARD, MOVE_BACKWARD_RIGHT, MOVE_RIGHT)
            if(strength > 50){
                for(i in 1 .. 9){
                    if(angle < i * 45 - 22.5){
                        send(moves[i - 1])
                        break
                    }
                }
            }
        }

        //Show and hide arm controllers
        toggleShowArm.setOnCheckedChangeListener { _, isChecked ->
            if(isChecked){
                arm.visibility = View.INVISIBLE
                armIcon.visibility = View.INVISIBLE
                toggleArmJaw.visibility = View.INVISIBLE
            }else{
                arm.visibility = View.VISIBLE
                armIcon.visibility = View.VISIBLE
                toggleArmJaw.visibility = View.VISIBLE
            }
        }


        //Check bluetooth
        toggleBluetoothIcon()
        connectBluetooth.setOnClickListener { connectToBluetooth() }

    }

    private fun hideSystemBars() {
        val windowInsetsController = ViewCompat.getWindowInsetsController(window.decorView) ?: return
        windowInsetsController.systemBarsBehavior = WindowInsetsControllerCompat.BEHAVIOR_SHOW_TRANSIENT_BARS_BY_SWIPE
        windowInsetsController.hide(WindowInsetsCompat.Type.systemBars())
    }

    private fun send(command:String){
        if(!bAdapter.isEnabled) connectToBluetooth()
        if(connected){
            val cmd = command.toByteArray()
            try{
                bSocket?.outputStream?.write(cmd)
            }catch (e: IOError){
                connected = false;
                toggleConnectedDevice(null);
                Toast.makeText(this, "Connect to bluetooth first", Toast.LENGTH_SHORT).show()
            }
        }else Toast.makeText(this, "Connect to bluetooth first", Toast.LENGTH_SHORT).show()
    }
    private fun send(command:Char) = send(command.toString())

    private fun toggleBluetoothIcon(){
        if(!bAdapter.isEnabled) bluetoothIcon.setColorFilter(Color.rgb(80,12,0))
        else bluetoothIcon.setColorFilter(Color.rgb(0,32,80))
    }

    private fun connectToBluetooth(){
        toggleBluetoothIcon()
        if(!bAdapter.isEnabled || !connected){
            if (Build.VERSION.SDK_INT >= Build.VERSION_CODES.S) {
                requestMultiplePermissions.launch(arrayOf(Manifest.permission.BLUETOOTH_SCAN, Manifest.permission.BLUETOOTH_CONNECT))
            }else{
                val enableBtIntent = Intent(BluetoothAdapter.ACTION_REQUEST_ENABLE)
                requestBluetooth.launch(enableBtIntent)
            }
        }
    }
    private fun toggleConnectedDevice(deviceName: String?){
        if(deviceName != null) connectBluetooth.text = deviceName
        else connectBluetooth.text = "Connect"
    }

    private val mReceiver: BroadcastReceiver = object : BroadcastReceiver(){
        var device: BluetoothDevice? = null
        @SuppressLint("MissingPermission")
        override fun onReceive(context: Context?, intent: Intent?) {
            val action = intent?.action
            device = intent?.getParcelableExtra(BluetoothDevice.EXTRA_DEVICE)
            if(BluetoothDevice.ACTION_FOUND == action){
                Log.v("Test", "Found")
            }else if (BluetoothDevice.ACTION_ACL_CONNECTED == action) {
                if (ActivityCompat.checkSelfPermission(c, Manifest.permission.BLUETOOTH_CONNECT) == PackageManager.PERMISSION_GRANTED) {
                    val name = device?.name
                    val addr = device?.address
                    toggleConnectedDevice(name)
                    bSocket = device?.createRfcommSocketToServiceRecord(uuid)
                    bSocket?.connect()
                    Log.v("Test", "Name = $name, Address = $addr")
                }
                connected = true
            }else if (BluetoothDevice.ACTION_ACL_DISCONNECTED == action) {
                bSocket?.close()
                bSocket = null
                connected = false
                toggleConnectedDevice(null)
                Log.v("Test", "Disconnected")
            }
        }
    }

    @SuppressLint("MissingPermission")
    private var requestBluetooth = registerForActivityResult(ActivityResultContracts.StartActivityForResult()) { result ->
        if (result.resultCode == RESULT_OK) {
            toggleBluetoothIcon()
            pairedDevices = bAdapter.bondedDevices
            val filter = IntentFilter()
            filter.addAction(BluetoothDevice.ACTION_ACL_CONNECTED)
            filter.addAction(BluetoothDevice.ACTION_ACL_DISCONNECT_REQUESTED)
            filter.addAction(BluetoothDevice.ACTION_ACL_DISCONNECTED)
            this.registerReceiver(mReceiver, filter)

            if(!connected){
                val openSettingsIntent = Intent(android.provider.Settings.ACTION_BLUETOOTH_SETTINGS)
                openSettingsIntent.addFlags(Intent.FLAG_ACTIVITY_NEW_TASK)
                startActivity(openSettingsIntent)
            }
        }else Toast.makeText(this, "Please enable bluetooth", Toast.LENGTH_SHORT).show()
    }

    private val requestMultiplePermissions =
        registerForActivityResult(ActivityResultContracts.RequestMultiplePermissions()) { permissions ->
            permissions.entries.forEach {
                if(it.value == true){
                    val enableBtIntent = Intent(BluetoothAdapter.ACTION_REQUEST_ENABLE)
                    requestBluetooth.launch(enableBtIntent)
                }
            }
        }
}





