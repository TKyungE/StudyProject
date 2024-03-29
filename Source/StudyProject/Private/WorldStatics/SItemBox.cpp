// Fill out your copyright notice in the Description page of Project Settings.


#include "WorldStatics/SItemBox.h"
#include "Components/BoxComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Particles/ParticleSystemComponent.h"

// Sets default values
ASItemBox::ASItemBox()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	BoxComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxComponent"));
	SetRootComponent(BoxComponent);
	BoxComponent->SetBoxExtent(FVector(40.f, 42.f, 30.f));
	BoxComponent->OnComponentBeginOverlap.AddDynamic(this, &ASItemBox::OnOverlapBegin);
	//BoxComponent->SetCollisionProfileName(FName("Trigger"));
	BoxComponent->SetCollisionProfileName(FName("SItemBox"));

	StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMeshComponent"));
	StaticMeshComponent->SetupAttachment(GetRootComponent());
	StaticMeshComponent->SetRelativeLocation(FVector(0.f, -3.5f, -30.f));
	StaticMeshComponent->SetCollisionProfileName(TEXT("NoCollision"));

	ParticleSystemComponent = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("ParticleSystemComponent"));
	ParticleSystemComponent->SetupAttachment(GetRootComponent());
	ParticleSystemComponent->SetAutoActivate(false);


}

void ASItemBox::OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepHitResult)
{
	ParticleSystemComponent->Activate(true);
	StaticMeshComponent->SetHiddenInGame(true);
	SetActorEnableCollision(false);
	ParticleSystemComponent->OnSystemFinished.AddDynamic(this, &ASItemBox::OnEffectFinish);
}

void ASItemBox::OnEffectFinish(UParticleSystemComponent* ParticleSystem)
{
	Destroy();
}

