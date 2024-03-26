// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/SNonPlayerCharacter.h"
#include "Controllers/SAIController.h"

ASNonPlayerCharacter::ASNonPlayerCharacter()
{
    PrimaryActorTick.bCanEverTick = false;

    AIControllerClass = ASAIController::StaticClass();
    AutoPossessAI = EAutoPossessAI::PlacedInWorldOrSpawned;
    // ASNonPlayerCharacter�� ������ ��ġ�ǰų� ���Ӱ� �����Ǹ� SAIController�� ���ǰ� �ڵ����� �����.
}
