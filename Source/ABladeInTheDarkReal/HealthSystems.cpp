// Fill out your copyright notice in the Description page of Project Settings.


#include "HealthSystems.h"

UHealthSystems::UHealthSystems()
{
	MaxHealth = 100.0f;
	CurrentHealth = MaxHealth;
}

void UHealthSystems::TakeDamage(float DamageAmount)
{
	CurrentHealth -= DamageAmount;

	if (CurrentHealth < 0.0f)
	{
		CurrentHealth = 0.0f;
	}
}

