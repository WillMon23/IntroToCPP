#pragma once

class Entity
{
public:
	/// <summary>
	/// Entity deconstructor
	/// </summary>
	/// <param name="icon"> Icon displayed</param>
	/// <param name="health"></param>
	/// <param name="attackPower"></param>
	/// <param name="defensePower"></param>
	Entity(char icon, float health, float attackPower, float defensePower);

	/// <summary>
	/// Entity access to health 
	/// </summary>
	/// <returns> float </returns>
	float getHealth() { return m_health; }
	/// <summary>
	/// Entity access to attack power 
	/// </summary>
	/// <returns> float </returns>
	float getAttackPower() { return m_attackPower; }
	/// <summary>
	/// Entity access to defense power
	/// </summary>
	/// <returns> float </returns>
	float getDefensePower() { return m_defensePower; }
	/// <summary>
	/// Organizes the action of taking damage
	/// by removing health by the damage amount
	/// </summary>
	/// <param name="damageAmount">damage being done to health</param>
	/// <returns>the defrense from health and damaage taken</returns>
	float takeDamage(float damageAmount);
	float attack(Entity entity);
private:
	char m_icon;
	float m_health;
	float m_attackPower;
	float m_defensePower;
};