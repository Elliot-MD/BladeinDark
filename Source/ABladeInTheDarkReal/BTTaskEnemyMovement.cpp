// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTaskEnemyMovement.h"
#include "AIController.h"
#include "EnemyAIController.h"
#include "Runtime/NavigationSystem/Public/NavigationSystem.h"
#include "BehaviorTree/BlackboardComponent.h"

//Making the name for the node on blueprint and adding size of walkable area
UBTTaskEnemyMovement::UBTTaskEnemyMovement()
{
	NodeName = "Movement";
	WanderRadius = 500.0f;	BlackboardKey.AddVectorFilter(this, GET_MEMBER_NAME_CHECKED(UBTTaskEnemyMovement, BlackboardKey));
}

//Creating the node for the blueprint
EBTNodeResult::Type UBTTaskEnemyMovement::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	FNavLocation Location{};

	//Here we get the AI Pawn
	AAIController* AIController{ OwnerComp.GetAIOwner() };
	if (AIController != nullptr)
	{
		const APawn* AIPawn = { AIController->GetPawn() };
		if (AIPawn != nullptr) 
		{
			//Here we will get the origin of the pawn
			const FVector Origin{ AIPawn->GetActorLocation() };

			//Here we obtain the navigation system and find a random location around the map
			const UNavigationSystemV1* NavSystem{ UNavigationSystemV1::GetCurrent(GetWorld()) };

			if (IsValid(NavSystem) && NavSystem->GetRandomPointInNavigableRadius(Origin, WanderRadius, Location))
			{
				AIController->GetBlackboardComponent()->SetValueAsVector(BlackboardKey.SelectedKeyName, Location.Location);
			}
		}
		//Tells the behaviour tree component that the task was completed successfully
		FinishLatentTask(OwnerComp, EBTNodeResult::Succeeded);
		return EBTNodeResult::Succeeded;
	}
	FinishLatentTask(OwnerComp, EBTNodeResult::Failed);
	return EBTNodeResult::Failed;
}


