// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SWeapon.generated.h"

UENUM(BlueprintType)
enum class EWeaponType : uint8
{
	None = 0,
	Knife = 1,
	End
};

UCLASS()
class STUDYPROJECT_API ASWeapon : public AActor
{
	GENERATED_BODY()

public:
	ASWeapon();

	TObjectPtr<class USkeletalMeshComponent> GetMesh() const { return SkeletalMeshComponent; }
	EWeaponType GetWeaponType() const { return WeaponType; }

protected:
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="ASWeapon", meta= (AllowPrivateAccess))
	TObjectPtr<class USkeletalMeshComponent> SkeletalMeshComponent;

	EWeaponType WeaponType;
};
