// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/SW_HPBar.h"
#include "Components/ProgressBar.h"
#include "Characters/SCharacter.h"
#include "Components/SStatComponent.h"

void USW_HPBar::SetMaxHP(float InMaxHP)
{
	SetMaxFigure(InMaxHP);
}

void USW_HPBar::InitializeHPBarWidget(USStatComponent* newStatComponent)
{
	OnCurrentHPChange(0, newStatComponent->GetCurrentHP());
}

void USW_HPBar::OnMaxHPChange(float InOldMaxHP, float InNewMaxHP)
{
	SetMaxFigure(InNewMaxHP);

	OnCurrentHPChange(0, InNewMaxHP);
}


void USW_HPBar::OnCurrentHPChange(float InOldHP, float InNewHP)
{
	if (true == ::IsValid(Bar))
	{
		if (KINDA_SMALL_NUMBER < MaxFigure)
		{
			Bar->SetPercent(InNewHP / MaxFigure);
		}
		else
		{
			Bar->SetPercent(0.f);
		}
	}
}

void USW_HPBar::NativeConstruct()
{
	Super::NativeConstruct();

	ASCharacter* OwningCharacter = Cast<ASCharacter>(OwningActor);
	if (true == ::IsValid(OwningCharacter))
	{
		OwningCharacter->SetWidget(this);
	}
}
