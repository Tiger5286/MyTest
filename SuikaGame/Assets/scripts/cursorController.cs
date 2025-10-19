using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using static UnityEditor.PlayerSettings;

public class cursorController : MonoBehaviour
{
    public float MoveSpeed;
    public float MoveLimit;

    public GameObject BerryPrefab;
    public GameObject StrawberryPrefab;
    public GameObject GrapePrefab;
    public GameObject DekoponPrefab;
    public GameObject OrangePrefab;

    bool isHaveFruit = true;
    GameObject haveFruit;
    CollisionNotifier2D notifier;

    private void Start()
    {
        Vector3 pos = transform.position;
        pos.y -= 1f;
        haveFruit = Instantiate(BerryPrefab, pos, Quaternion.identity);
        notifier = haveFruit.GetComponent<CollisionNotifier2D>();
        if (notifier != null )
        {
            notifier.OnCollided += HandleCollision;
        }
        else
        {

            Debug.LogWarning($"CollisionNotifier2D が{haveFruit.name}にアタッチされていません。");
        }
    }

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

        if (Input.GetKeyDown(KeyCode.Space))
        {
            isHaveFruit = false;
        }

        if (isHaveFruit)
        {
            pos = transform.position;
            pos.y -= 1f;
            haveFruit.transform.position = pos;
        }
    }

    void HandleCollision(Collision2D collision)
    {
        Vector3 pos = transform.position;
        switch (Random.Range(0, 4))
        {
            case 0:
                haveFruit = Instantiate(BerryPrefab, pos, Quaternion.identity);
                break;
            case 1:
                haveFruit = Instantiate(StrawberryPrefab, pos, Quaternion.identity);
                break;
            case 2:
                haveFruit = Instantiate(GrapePrefab, pos, Quaternion.identity);
                break;
            case 3:
                haveFruit = Instantiate(DekoponPrefab, pos, Quaternion.identity);
                break;
            case 4:
                haveFruit = Instantiate(OrangePrefab, pos, Quaternion.identity);
                break;
        }
        notifier = haveFruit.GetComponent<CollisionNotifier2D>();
        Debug.Log($"監視対象が {haveFruit.name} になりました");
        isHaveFruit = true;
    }
}
