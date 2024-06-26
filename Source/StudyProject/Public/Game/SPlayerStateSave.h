// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/SaveGame.h"
#include "SPlayerStateSave.generated.h"


UENUM(BlueprintType)
enum class ETeamType : uint8
{
	None,
	Red,
	Blue,
	End
};
/**
 * 
 */
UCLASS()
class STUDYPROJECT_API USPlayerStateSave : public USaveGame
{
	GENERATED_BODY()
	
public:
	USPlayerStateSave();

public:
	UPROPERTY()
	FString PlayerCharacterName;

	UPROPERTY()
	int32 CurrentLevel;

	UPROPERTY()
	float CurrentEXP;

	UPROPERTY()
	ETeamType TeamType = ETeamType::Red;
};
