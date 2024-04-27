// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "STPSAnimInstance.generated.h"

/**
 * 
 */
UCLASS()
class STUDYPROJECT_API USTPSAnimInstance : public UAnimInstance
{
	GENERATED_BODY()
	
public:
	USTPSAnimInstance();

	virtual void NativeInitializeAnimation() override;
	
	virtual void NativeUpdateAnimation(float DeltaSeconds) override;

private:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category ="USTPSAnimInstance", Meta=(AllowPrivateAccess = true))
	TObjectPtr<class ASTPSCharacter> OwnerCharacter;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "USTPSAnimInstance", Meta=(AllowPrivateAccess = true))
	TObjectPtr<class UCharacterMovementComponent> MovementComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "USTPSAnimInstance", Meta = (AllowPrivateAccess = true))
	float GroundSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "USTPSAnimInstance", Meta = (AllowPrivateAccess= true))
	FVector MoveInputWithMaxSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "USTPSAnimInstance", Meta = (AllowPrivateAccess = true))
	FVector MoveInput;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "USTPSAnimInstance", Meta = (AllowPrivateAccess = true))
	uint8 bIsFalling : 1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "USTPSAnimInstance", Meta = (AllowPrivateAccess = true))
	uint8 bIsDead : 1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "USTPSAnimInstance", Meta = (AllowPrivateAccess = true))
	FRotator ControlRotation;
};
