using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class cursorController : MonoBehaviour
{
    public float MoveSpeed;
    public float MoveLimit;

    public GameObject FruitPrefab;

    void Update()
    {
        // 矢印キーで左右移動
        if (Input.GetKey(KeyCode.RightArrow))
        {
            transform.position += Vector3.right * Time.deltaTime * MoveSpeed;
        }
        if (Input.GetKey(KeyCode.LeftArrow))
        {
            transform.position += Vector3.left * Time.deltaTime * MoveSpeed;
        }

        // 移動距離に制限
        Vector3 pos = transform.position;
        if (pos.x < -MoveLimit)
        {
            pos.x = -MoveLimit;
        }
        if (pos.x > MoveLimit)
        {
            pos.x = MoveLimit;
        }
        transform.position = pos;

        // フルーツを落とす(仮)
        if (Input.GetKeyDown(KeyCode.Space))
        {
            pos = transform.position;
            pos.y -= 1;
            Instantiate(FruitPrefab,pos,Quaternion.identity);
        }
    }
}
