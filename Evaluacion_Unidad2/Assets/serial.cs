using UnityEngine;
using System.IO.Ports;
using TMPro;
using UnityEngine.UI;

enum TaskState
{
    INIT,
    WAIT_COMMANDS
}

public class serial : MonoBehaviour
{
    private static TaskState taskState = TaskState.INIT;
    private SerialPort _serialPort;
    private byte[] buffer;
    public TextMeshProUGUI myText;
    public TextMeshProUGUI boton1state;
    public TextMeshProUGUI boton2state;
    public TextMeshProUGUI boton3state;
    public TMP_Dropdown drop_Led;
    public TMP_Dropdown drop_State;
    private int counter = 0;
    private bool read = false;
    private bool On = false;
    private bool Off = false;
    private bool changeState = false;
    void Start()
    {
        _serialPort = new SerialPort();
        _serialPort.PortName = "/dev/ttyACM0";
        _serialPort.BaudRate = 115200;
        _serialPort.DtrEnable = true;
        _serialPort.NewLine = "\n";
        _serialPort.Open();
        Debug.Log("Open Serial Port");
        buffer = new byte[128];
    }

    void Update()
    {
        myText.text = counter.ToString();
        counter++;

        switch (taskState)
        {
            case TaskState.INIT:
                taskState = TaskState.WAIT_COMMANDS;
                Debug.Log("WAIT COMMANDS");
                break;
            case TaskState.WAIT_COMMANDS:
                if (read == true)
                {
                    _serialPort.Write("readBUTTONS\n");
                    Debug.Log("Send readBUTTONS");
                    read = false;
                }

                if (changeState == true)
                {
                    if (drop_State.value == 0)
                    {
                        On = true;
                    }
                    else if (drop_State.value == 1)
                    {
                        Off = true;
                    }
                    
                    if (drop_Led.value == 0)
                    {
                        if (On == true)
                        {
                            _serialPort.Write("led1ON\n");
                            Debug.Log("Send led1ON");
                            On = false;
                        }
                        else if (Off == true)
                        {
                            _serialPort.Write("led1OFF\n");
                            Debug.Log("Send led1OFF");
                            Off = false;
                        }
                        
                    }
                    else if (drop_Led.value == 1)
                    {
                        if (On == true)
                        {
                            _serialPort.Write("led2ON\n");
                            Debug.Log("Send led2ON");
                            On = false;
                        }
                        else if (Off == true)
                        {
                            _serialPort.Write("led2OFF\n");
                            Debug.Log("Send led2OFF");
                            Off = false;
                        }
                    }
                    else if (drop_Led.value == 2)
                    {
                        if (On == true)
                        {
                            _serialPort.Write("led3ON\n");
                            Debug.Log("Send led3ON");
                            On = false;
                        }
                        else if (Off == true)
                        {
                            _serialPort.Write("led3OFF\n");
                            Debug.Log("Send led3OFF");
                            Off = false;
                        }
                        
                    }
                    else if (drop_Led.value == 3)
                    {
                        if (On == true)
                        {
                            _serialPort.Write("led4ON\n");
                            Debug.Log("Send led4ON");
                            On = false;
                        }
                        else if (Off == true)
                        {
                            _serialPort.Write("led4OFF\n");
                            Debug.Log("Send led4OFF");
                            Off = false;
                        }
                        
                    }

                    changeState = false;
                }
                if (_serialPort.BytesToRead > 0)
                {
                    string response = _serialPort.ReadLine();
                    char[] separators = new char[] { ',' };

                    string[] sincoma = response.Split(separators);
                    Debug.Log(response);
                    Debug.Log(sincoma[2]);
                    if (sincoma[0] == "0")
                    {
                        boton1state.text = "Released";
                    }
                    else if (sincoma[0] == "1")
                    {
                        boton1state.text = "Pushed";
                    }
                    if (sincoma[1] == "0")
                    {
                        boton2state.text = "Released";
                    }
                    else if (sincoma[1] == "1")
                    {
                        boton2state.text = "Pushed";
                    }
                    if (sincoma[2] == "0")
                    {
                        boton3state.text = "Released";
                    }
                    else if (sincoma[2] == "1")
                    {
                        boton3state.text = "Pushed";
                    }
                }

                break;
            default:
                Debug.Log("State Error");
                break;
        }
    }

    public void OnButtonReadClick()
    {
        read = true;
    }
    public void OnButtonStateClick()
    {
        changeState = true;
    }
}