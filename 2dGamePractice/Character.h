#pragma once
#include "Vec2.h"
#include "Rect.h"

class Bg;

/// <summary>
/// キャラクターの基底クラス
/// </summary>
class Character
{
public:
	/// <summary>
	/// コンストラクタ
	/// </summary>
	Character();

	/// <summary>
	/// デストラクタ
	/// </summary>
	~Character();

	/// <summary>
	/// 初期化処理
	/// </summary>
	virtual void Init();

	/// <summary>
	/// 更新処理
	/// </summary>
	virtual void Update();

	/// <summary>
	/// 描画処理
	/// </summary>
	virtual void Draw();

	/// <summary>
	/// ダメージを受けた場合の処理
	/// </summary>
	void OnDamage();

	/// <summary>
	/// 位置を取得
	/// </summary>
	/// <returns>位置</returns>
	Vec2 GetPos() const { return m_pos; }

	/// <summary>
	/// HP取得
	/// </summary>
	/// <returns>HP</returns>
	int GetHp() const { return m_hp; }

	/// <summary>
	/// 当たり判定を取得
	/// </summary>
	/// <returns>当たり判定情報</returns>
	Rect GetColRect() const { return m_colRect; } // 当たり判定取得

	/// <summary>
	/// Bgクラスのポインタをセットする
	/// </summary>
	/// <param name="pBg">Bgクラスポインタ</param>
	void SetBgPointer(Bg* pBg) { m_pBg = pBg; }

protected:
	/// <summary>
	/// 重力処理
	/// </summary>
	void Gravity();

protected:
	// 画像ハンドル
	int m_handle;

	Vec2 m_pos;		 // 位置
	Vec2 m_move;	 // 移動量
	bool m_isLeft;	 // 左向きかどうか
	bool m_isGround; // 接地しているかどうか

	int m_hp;		   // HP
	int m_damageFrame; // ダメージを受けてからの経過フレーム数

	Bg* m_pBg;

	// 当たり判定用の矩形
	Rect m_colRect;
};

