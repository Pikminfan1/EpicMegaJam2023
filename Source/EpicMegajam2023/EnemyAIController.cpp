// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyAIController.h"
#include "Kismet/GameplayStatics.h"
#include "BehaviorTree/BlackboardComponent.h"
//#include "ShooterCharacter.h"

bool AEnemyAIController::IsDead() const
{
	/*AShooterCharacter* ControlledCharacter = Cast<AShooterCharacter>(GetPawn());
	if (ControlledCharacter != nullptr) {
		return ControlledCharacter->IsDead();
	}
	return true;*/
	return false;
}

void AEnemyAIController::BeginPlay() {
	Super::BeginPlay();
	if (AIBehavior != nullptr) {
		RunBehaviorTree(AIBehavior);

		APawn* PlayerPawn = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);

		GetBlackboardComponent()->SetValueAsVector(TEXT("StartLocation"), GetPawn()->GetActorLocation());
	}

}
void AEnemyAIController::Tick(float DeltaSeconds) {
	Super::Tick(DeltaSeconds);
}