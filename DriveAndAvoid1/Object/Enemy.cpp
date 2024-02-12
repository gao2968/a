#include "Enemy.h"
#include"DxLib.h"

Enemy::Enemy(int type, int handle):type(type),image(handle),speed(0.0f),location(0.0f),box_size(0.0f)
{

}

Enemy::Enemy(float _x, float _y, float _r, float _speed, float b_speed, int score, int _hp, int _E_num, int type, int handle) :type(type), image(handle)
{
	point = score;
	WaitTime = 0;
	E_num = _E_num;
	hp = _hp;
	speed = _speed;
	bullet_speed = b_speed;

	location.x = _x;
	location.y = _y;
	radius = _r;
}
// GameMainで使用

// new Enemy(e_spawn->LoadEnemy(E_num).location_x		// X座標取得
//			,e_spawn->LoadEnemy(E_num).location_y		// Y座標取得
//			,e_spawn->LoadEnemy(E_num).radius			// 半径取得
//			,e_spawn->LoadEnemy(E_num).speed			// スピード取得
//			,e_spawn->LoadEnemy(E_num).bullet_speed		// 球のスピード取得
//			,e_spawn->LoadEnemy(E_num).score			// 撃破時のスコア数取得
//			, e_spawn->LoadEnemy(E_num).hp				// HP取得
//			, E_num);									// 今何体目なのか

Enemy::~Enemy() 
{

}

// 処理化処理
void Enemy::Initialize() 
{
	// 出題させるX座標パターン取得
	float random_x = (float)(GetRand(4) * 105 + 40);
	// 生成位置の設定
	location = Vector2D(random_x, -50.0f);
	// あたり判定の設定
	box_size = Vector2D(31.0f, 60.0f);
	// 速さの設定
	speed = (float)(this->type * 2);
}

void Enemy::Update(float speed) 
{
	// 位置情報に移動量を加算する Yのみプラスしていく感じ
	
	location += Vector2D(0.0f, this->speed + speed - 6);
}

void Enemy::Draw()const
{
	// 敵画像描画
	DrawRotaGraphF(location.x, location.y, 1.0, 0.0, image, TRUE);

}

void Enemy::Finalize()
{
}

int Enemy::GetType() const
{
	return type;
}

Vector2D Enemy::GetLocation()
{
	return location;
}

Vector2D Enemy::GetBoxSize()
{
	return box_size;
}
