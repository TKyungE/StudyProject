// Fill out your copyright notice in the Description page of Project Settings.


#include "Items/SWeapon.h"

// Sets default values
ASWeapon::ASWeapon()
{
	PrimaryActorTick.bCanEverTick = false;

	SkeletalMeshComponent = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("SkeletalMeshComponent"));
	SetRootComponent(SkeletalMeshComponent);

	WeaponType = EWeaponType::None;
}



