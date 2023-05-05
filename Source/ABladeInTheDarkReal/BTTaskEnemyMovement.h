// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Tasks/BTTask_BlackboardBase.h"
#include "GameFramework/Pawn.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BehaviorTree/BehaviorTreeTypes.h"
#include "UObject/UObjectGlobals.h"
#include "BTTaskEnemyMovement.generated.h"

/**
 * 
 */
UCLASS()
class ABLADEINTHEDARKREAL_API UBTTaskEnemyMovement : public UBTTask_BlackboardBase
{
	GENERATED_BODY()

public:
	UBTTaskEnemyMovement();

	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;

private:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI", meta = (AllowPrivateAccess = "true"))
	float WanderRadius;
};
