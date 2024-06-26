// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "SCharacter.generated.h"

UCLASS()
class STUDYPROJECT_API ASCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	ASCharacter();

	//float GetMaxHP() const { return MaxHP; }
	//float GetCurrentHP() const { return CurrentHP; }
	//
	//void SetMaxHP(float InMaxHP) { MaxHP = InMaxHP; }
	//void SetCurrentHP(float InCurrentHP) { CurrentHP = InCurrentHP; }

	//bool IsDead() const { return bIsDead; }


	virtual void BeginPlay() override;

	virtual float TakeDamage(float Damage, struct FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser) override;

	class USStatComponent* GetStatComponent() { return StatComponent; }
	
	UFUNCTION()
	virtual void OnCharacterDeath();

	virtual void SetWidget(class UStudyUserWidget* InstudyUserWidget) {}

protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "ASTPSCharacter", Meta = (AllowPrivateAccess))
	TObjectPtr<class USpringArmComponent> SpringArmComponent;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "ASTPSCharacter", Meta = (AllowPrivateAccess))
	TObjectPtr<class UCameraComponent> CameraComponent;

	//UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "ASTPSCharacter", Meta = (AllowPrivateAccess))
	//float MaxHP = 200.f;
	//
	//UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "ASTPSCharacter", Meta = (AllowPrivateAccess))
	//float CurrentHP = 200.f;
	//
	//UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "ASTPSCharacter", Meta = (AllowPrivateAccess))
	//uint8 bIsDead : 1;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "ASPlayerCharacter", Meta = (AllowPrivateAccess))
	TObjectPtr<class USStatComponent> StatComponent;
};
