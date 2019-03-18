using UnityEngine;
using System.Linq;
using System.Collections;


public class OSCController : MonoBehaviour
{
    private int count;
    private float[] waveData_ = new float[1024];
    // Use this for initialization
    void Start()
    {
        // this line triggers the magic
        OSCHandler.Instance.Init();

    }

    // Update is called once per frame
    void Update()
    {
        count++;
        Vector3 tmp = GameObject.Find("Cube").transform.position;
        float xPos = tmp.x;
        float yPos = tmp.z;
        Vector3 scl = GameObject.Find("Cube").transform.localScale;
        float yScale = scl.y;
        AudioListener.GetOutputData(waveData_, 1);
        var volume = waveData_.Select(x => x * x).Sum() / waveData_.Length;
        this.transform.localScale = new Vector3(2, volume * 100, 2);
        float size = volume * 100000000;
        OSCHandler.Instance.SendMessageToClient("myRemoteLocation", "127.0.0.1:12000", xPos);
        OSCHandler.Instance.SendMessageToClient("SecondLocation", "127.0.0.1:10000", yPos);
    }
}