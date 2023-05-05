// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "HealthSystems.generated.h"

/**
 * 
 */
UCLASS()
class ABLADEINTHEDARKREAL_API UHealthSystems : public UObject
{
	GENERATED_BODY()

public:
	UHealthSystems();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float MaxHealth;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float CurrentHealth;

	UFUNCTION(BlueprintCallable)
	void TakeDamage(float DamageAmount);
};
