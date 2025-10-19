using System;
using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class CollisionNotifier2D : MonoBehaviour
{
    // 衝突イベントを外部に通知するためのイベント
    public event Action<Collision2D> OnCollided;

    private void OnCollisionEnter2D(Collision2D collision)
    {
        // 衝突が発生したときにイベントを発火
        OnCollided?.Invoke(collision);
    }

}
