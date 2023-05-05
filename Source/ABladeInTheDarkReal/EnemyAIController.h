// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "EnemyAIController.generated.h"

/**
 * 
 */
UCLASS()
class ABLADEINTHEDARKREAL_API AEnemyAIController : public AAIController
{
	GENERATED_BODY()

public:
	AEnemyAIController();
	virtual void OnPossess(APawn* InPawn) override;
	virtual void OnUnPossess() override;

protected:
	UPROPERTY(EditDefaultsOnly, Category = "AI")
	UBehaviorTree* BehaviorTree;

	UPROPERTY(EditDefaultsOnly, Category = "AI")
	UBlackboardData* BlackboardData;

	UPROPERTY(BlueprintReadOnly, Category = "AI")
	UBehaviorTreeComponent*  BehaviorTreeComponent;

	UPROPERTY(BlueprintReadOnly, Category = "AI")
	UBlackboardComponent* BlackboardComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI")
	UBehaviorTreeComponent* BehaviorComp;
};