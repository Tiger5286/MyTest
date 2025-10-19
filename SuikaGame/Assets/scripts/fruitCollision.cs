using System.Collections;
using System.Collections.Generic;
using UnityEngine;

// フルーツの種類
public enum FruitType
{
    Berry,
    Strawberry,
    Grape,
    Dekopon,
    Orange,
    Apple,
    Pear,
    Peach,
    Pineapple,
    Melon,
    Watermelon
}

public class fruitCollision : MonoBehaviour
{
    public FruitType ThisFruitTag;      // 自身のフルーツの種類
    public GameObject NextFruitPrefab;  // 合体後のフルーツのプレハブ

    private void OnCollisionEnter2D(Collision2D collision)
    {
        // 同じタグのオブジェクトが衝突したとき
        if (collision.gameObject.CompareTag(ThisFruitTag.ToString()) &&
            this.gameObject.CompareTag(ThisFruitTag.ToString()))
        {
            // 自分のIDが相手より小さいときだけ処理する(衝突したどちらかしか実行されない)
            if (this.gameObject.GetInstanceID() < collision.gameObject.GetInstanceID())
            {
                // スイカの時は次のプレハブを出現させない
                if (!this.gameObject.CompareTag("Watermelon"))
                {
                    // 衝突した二つのオブジェクトの真ん中に召喚
                    Vector3 spawnPos = (this.transform.position + collision.transform.position) / 2;
                    Instantiate(NextFruitPrefab, spawnPos, transform.rotation);
                }
            }
            // 衝突したオブジェクトを削除
            Destroy(this.gameObject);
        }
    }
}