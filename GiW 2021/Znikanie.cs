using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Znikanie : MonoBehaviour
{
    public AudioSource tick;
    public GameEnding gameEnding;
    // Start is called before the first frame update
    void Start()
    {
        tick = GetComponent<AudioSource>();
    }

    void OnCollisionEnter(Collision collision)
    {
        if (collision.gameObject.name == "JohnLemon")
        {
            
            Destroy(collision.gameObject);
            tick.Play();
            gameEnding.CaughtPlayer();

        }
    }

}
