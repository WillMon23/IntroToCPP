#pragma once

class Entity
{
public:
	Entity(char icon, float health, float attackPower, float defensePower);

	float getHealth() { return m_health; }
	float getAttackPower() { return m_attackPower; }
	float getDefensePower() { return m_defensePower; }
	
	float takeDamage(float damageAmount);
	float attack(Entity entity);
private:
	char m_icon;
	float m_health;
	float m_attackPower;
	float m_defensePower;
};