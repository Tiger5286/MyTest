using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class fruitCollision : MonoBehaviour
{
    public string ThisFruitTag;

    public GameObject NextFruitPrefab;

    private void OnCollisionEnter2D(Collision2D collision)
    {
        if (collision.gameObject.CompareTag(ThisFruitTag) && this.gameObject.CompareTag(ThisFruitTag))
        {

            // ©•ª‚ÌID‚ª‘Šè‚æ‚è¬‚³‚¢‚Æ‚«‚¾‚¯ˆ—‚·‚é(Õ“Ë‚µ‚½‚Ç‚¿‚ç‚©‚µ‚©Às‚³‚ê‚È‚¢)
            if (this.gameObject.GetInstanceID() < collision.gameObject.GetInstanceID())
            {
                Instantiate(NextFruitPrefab, transform.position, transform.rotation);
            }
            Destroy(this.gameObject);
        }
    }
}