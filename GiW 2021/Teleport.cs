using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Teleport : MonoBehaviour
{
    public GameObject player;
    public CanvasGroup exitBackgroundImageCanvasGroup;
    public AudioSource exitAudio;
    public float fadeDuration = 1f;
    public float displayImageDuration = 1f;
    public GameEnding gameEnding;

    bool isPlayerAtTransition;
    bool audioPlayed;
    float timer;

    private void Update()
    {
        if (isPlayerAtTransition)
        {
            Transition(exitBackgroundImageCanvasGroup, exitAudio);
        }
    }

    void OnTriggerEnter(Collider other)
    {
        isPlayerAtTransition = true;
    }

    void Transition(CanvasGroup imageCanvasGroup, AudioSource audioSource)
    {
        if (!audioPlayed)
        {
            audioSource.Play();
            audioPlayed = true;
        }

        timer += Time.deltaTime;
        imageCanvasGroup.alpha = timer / fadeDuration;

        if (timer > fadeDuration + displayImageDuration)
        {
            player.transform.position = new Vector3(30f, 0f, -13.2f);
            imageCanvasGroup.alpha = 0;
            audioSource.Stop();
            isPlayerAtTransition = false;
            gameEnding.doRestart = false;
        }
    }
}