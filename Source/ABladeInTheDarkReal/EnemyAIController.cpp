// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyAIController.h"
//#include "GameplayTask.h"
//#include "GameplayTaskOwnerInterface.h"

AEnemyAIController::AEnemyAIController()
{
}

void AEnemyAIController::OnPossess(APawn* InPawn)
{
	//Super:OnPossess(InPawn);

	//Initialise the behaviour tree and the blackboard components
	if (BehaviorTree != nullptr)
	{
		BehaviorTreeComponent->StartTree(*BehaviorTree);
		BlackboardComponent->InitializeBlackboard(*BlackboardData);

		BlackboardComponent->SetValueAsFloat("WanderRadius", 300.0f);
	}

	
}

void AEnemyAIController::OnUnPossess()
{
	Super::OnUnPossess();
}

