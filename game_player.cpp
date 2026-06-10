#include "stdafx.h"
#include "game_player.h"

void GamePlayer::Update(float delta_time)
{
	move(delta_time);

	attack();
}

void GamePlayer::Draw() const
{
	if (m_is_attack) {
		TextureAsset(U"Player_Attack").drawAt(GetPosition());
	}
	else {
		TextureAsset(U"Player_Normal").drawAt(GetPosition());
	}
}

void GamePlayer::Damage(const GameDamage&)
{

}

void GamePlayer::move(float delta_time)
{
	Float2 dir{};

	if (KeyW.pressed()) {
		dir.y += -1.0f;
	}
	if (KeyS.pressed()) {
		dir.y += 1.0f;
	}
	if (KeyA.pressed()) {
		dir.x += -1.0f;
	}
	if (KeyD.pressed()) {
		dir.x += 1.0f;
	}

	if (!dir.isZero()) {
		dir.normalize();
	}

	constexpr float PLAYER_MOVE_SPEED{ 128.0f };

	SetPosition(GetPosition() + dir * PLAYER_MOVE_SPEED * delta_time);
