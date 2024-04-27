// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Characters/SCharacter.h"
#include "InputActionValue.h"
#include "STPSCharacter.generated.h"

/**
 * 
 */
UCLASS()
class STUDYPROJECT_API ASTPSCharacter : public ASCharacter
{
	GENERATED_BODY()
	
public:
	ASTPSCharacter();

	virtual void BeginPlay() override;

	virtual void Tick(float DeltaSeconds) override;

	float GetForwardInputValue() const { return ForwardInputValue; }

	float GetRightInputValue() const { return RightInputValue; }

	float GetCurrentAimPitch() const { return CurrentAimPitch; }

	float GetCurrentAimYaw() const { return CurrentAimYaw; }

	virtual float TakeDamage(float Damage, struct FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser) override;

	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

protected:
	virtual void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) override;

private:
	void Move(const FInputActionValue& InValue);

	void Look(const FInputActionValue& InValue);

	void Attack(const FInputActionValue& InValue);

	void Fire();

	void ToggleTrigger(const FInputActionValue& InValue);

	void StartIronSight(const FInputActionValue& InValue);
	void EndIronSight(const FInputActionValue& InValue);

	void StartFire(const FInputActionValue& InValue);
	void StopFire(const FInputActionValue& InValue);

	UFUNCTION()
	void OnHittedRagdollRestoreTimerElapesd();

	void SpawnLandMine(const FInputActionValue& InValue);

	UFUNCTION(Server, Reliable, WithValidation)
	void SpawnLandMine_Server();

	UFUNCTION(Server, Unreliable)
	void UpdateInputValue_Server(const float& InForwardInputValue, const float& InRightInputValue);

	UFUNCTION(Server, Unreliable)
	void UpdateAimValue_Server(const float& InAimPitchValue, const float& InAimYawValue);

	UFUNCTION(Server, Unreliable)
	void PlayAttackMontage_Server();

	UFUNCTION(NetMulticast, Unreliable)
	void PlayAttackMontage_NetMulticast();


private:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category= "ASTPSCharacter", Meta = (AllowPrivateAccess))
	TObjectPtr<USkeletalMeshComponent> WeaponSkeletalMeshComponent;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "ASTPSCharacter", Meta = (AllowPrivateAccess))
	TObjectPtr<class USInputConfigData> PlayerCharacterInputConfigData;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "ASTPSCharacter", Meta = (AllowPrivateAccess))
	TObjectPtr<class UInputMappingContext> PlayerCharacterInputMappingContext;

	UPROPERTY(Replicated,VisibleAnywhere, BlueprintReadOnly, Category = "ASTPSCharacter", Meta = (AllowPrivateAccess))
	float ForwardInputValue;

	float PreviousForwardInputValue = 0.f;

	UPROPERTY(Replicated,VisibleAnywhere, BlueprintReadOnly, Category = "ASTPSCharacter", Meta = (AllowPrivateAccess))
	float RightInputValue;

	float PreviousRightInputValue = 0.f;

	float TargetFOV = 70.f;
	float CurrentFOV = 70.f;

	bool bIsTriggerToggle = false;

	UPROPERTY(EditDefaultsOnly, Category = "ASTPSCharacter", Meta = (AllowPrivateAccess))
	float FirePerMinute = 600;

	FTimerHandle BetweenShotsTimer;
	
	float TimeBetweenFire;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "ASTPSCharacter", Meta = (AllowPrivateAccess))
	TObjectPtr<class UAnimMontage> RifleFireAnimMontage;

	UPROPERTY(Replicated, VisibleAnywhere, BlueprintReadOnly, Category = "ASTPSCharacter", Meta = (AllowPrivateAccess))
	float CurrentAimPitch = 0.f;

	float PreviousAimPitch = 0.f;

	UPROPERTY(Replicated, VisibleAnywhere, BlueprintReadOnly, Category = "ASTPSCharacter", Meta = (AllowPrivateAccess))
	float CurrentAimYaw = 0.f;

	float PreviousAimYaw = 0.f;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "ASTPSCharacter", Meta = (AllowPrivateAccess))
	TSubclassOf<class UCameraShakeBase> FireShake;

	FTimerHandle HittedRagdollRestoreTimer;
	FTimerDelegate HittedRagdollRestoreTimerDelegate;

	float TargetRagDollBlendWeight = 0.f;
	
	float CurrentRagDollBlendWeight = 0.f;

	bool bIsNowRagDollBlending = false;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "ASTPSCharacter", Meta = (AllowPrivateAccess))
	TSubclassOf<class AActor> LandMineClass;
};
