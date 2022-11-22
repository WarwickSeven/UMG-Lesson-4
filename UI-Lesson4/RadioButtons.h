// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/Widget.h"
#include "RadioButtons.generated.h"

class SRadioButtons;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnRadioButtonChangedEvent, int32, NewSelectedButton);

UCLASS()
class SLATEPROJECT_API URadioButtons : public UWidget
{
	GENERATED_BODY()

public:

//Specify widget category
#if WITH_EDITOR
	virtual const FText GetPaletteCategory() override { return FText::FromString(TEXT("Input")); };
#endif

	UPROPERTY(BlueprintAssignable)
	FOnRadioButtonChangedEvent OnRadioButtonChanged;

	UPROPERTY(EditAnywhere, Category="Raws")
	int32 Count = 3;

	UPROPERTY(EditAnywhere, Category="Raws")
	int32 DefaultCheck = 0;
	
	int32 GetCount() const { return Count; }

	int32 GetDefaultCheck() const { return DefaultCheck; }
		
	virtual void ReleaseSlateResources(bool bReleaseChildren) override;
	
protected:

	virtual TSharedRef<SWidget> RebuildWidget() override;

private:
	
	TSharedPtr<SRadioButtons> RadioButtons;

	void OnRadioButtonChangedFunc(int32 NewSelectedButton);
};
