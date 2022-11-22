// Fill out your copyright notice in the Description page of Project Settings.


#include "RadioButtons.h"
#include "SRadioButtons.h"
#include "Widgets/Layout/SSpacer.h"

void URadioButtons::ReleaseSlateResources(bool bReleaseChildren)
{
	Super::ReleaseSlateResources(bReleaseChildren);
	RadioButtons.Reset();
}

TSharedRef<SWidget> URadioButtons::RebuildWidget()
{
	RadioButtons = SNew(SRadioButtons)
		.Count_UObject(this, &ThisClass::GetCount)
		.DefaultCheck_UObject(this, &ThisClass::GetDefaultCheck)
		.OnRadioButtonChanged_UObject(this, &URadioButtons::OnRadioButtonChangedFunc);

	return RadioButtons.ToSharedRef();
}

void URadioButtons::OnRadioButtonChangedFunc(int32 NewSelectedButton)
{
	OnRadioButtonChanged.Broadcast(NewSelectedButton);
}

