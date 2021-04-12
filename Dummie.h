// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Dummie.generated.h"

UCLASS()
class TS_GABRIEL_CABRERA_API ADummie : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ADummie();


	UPROPERTY(EditAnywhere, Category = "Properties")
		class UStaticMeshComponent* Mesh;

	UPROPERTY(EditAnywhere, Category = "Properties")
		UDecalComponent* DecalComponent;

		/* Handle to manage the timer */
		FTimerHandle FuzeTimerHandle;

		bool bIsHit;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION()
	void SetRotation(float r);


};
