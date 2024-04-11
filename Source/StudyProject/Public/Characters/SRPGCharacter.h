// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Characters/SCharacter.h"
#include "InputActionValue.h"
#include "SRPGCharacter.generated.h"

/**
 * 
 */
UCLASS()
class STUDYPROJECT_API ASRPGCharacter : public ASCharacter
{
	GENERATED_BODY()

	friend class UAN_CheckHit;

public:
	ASRPGCharacter();

	virtual void BeginPlay() override;

	float GetForwardInputValue() const { return ForwardInputValue; }
	float GetRightInputValue() const { return RightInputValue; }

	UFUNCTION()
	void OnAttackMontageEnded(UAnimMontage* Montage, bool bInterruped);

	virtual float TakeDamage(float Damage, struct FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser) override;

	void Menu(const FInputActionValue& InValue);

protected:
	virtual void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) override;

private:
	void Move(const FInputActionValue& InValue);
	void Look(const FInputActionValue& InValue);
	void Attack(const FInputActionValue& InValue);

	void BeginCombo();

	UFUNCTION()
	void CheckHit();

	UFUNCTION()
	void CheckCanNextCombo();

	UFUNCTION()
	void EndCombo(class UAnimMontage* InAnimMontage, bool bInterrupted);

	UFUNCTION()
	void OnCurrentLevelChanged(int32 InOldCurrentLevel, int32 InNewCurrentLevel);

	UFUNCTION()
	void OnAssetLoaded();

private:
	UPROPERTY(EditAnywhere,BlueprintReadOnly, Category="ASRPGCharacter", Meta = (AllowPrivateAccess))
	TObjectPtr<class USInputConfigData> PlayerCharacterInputConfigData;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "ASRPGCharacter", Meta = (AllowPrivateAccess))
	TObjectPtr<class UInputMappingContext> PlayerCharacterInputMappingContext;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "ASRPGCharacter", Meta = (AllowPrivateAccess))
	float ForwardInputValue;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "ASRPGCharacter", Meta = (AllowPrivateAccess))
	float RightInputValue;

	uint8 bIsAttacking : 1;

	FString AttackAnimMontageSectionName = FString(TEXT("Attack"));

	int32 MaxComboCount = 3;

	int32 CurrentComboCount = 0;	

	bool bIsAttackKeyPressed = false;

	float AttackRange = 200.f;
	float AttackRadius = 50.f;

	UPROPERTY(EditAnywhere,BlueprintReadOnly, Category = "ASRPGCharacter", Meta = (AllowPrivateAccess))
	TObjectPtr<class UParticleSystemComponent> ParticleSystemComponent;

	FSoftObjectPath CurrentPlayerCharacterMeshPath = FSoftObjectPath();

	TSharedPtr<struct FStreamableHandle> AssetStreamableHandle = nullptr;

};
