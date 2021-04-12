// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Gun.generated.h"

UCLASS()
class TS_GABRIEL_CABRERA_API AGun : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AGun();

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Properties")
		float damage = 10.f;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Properties")
		float cooldown = 0.75f;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Properties")
		float max_Ammo = 10.f;

	UPROPERTY(BlueprintReadOnly, Category = "Properties")
		float current_Ammo;

	/*This variable change in  the character to get the end point of the laser*/
	FVector end;
	UPROPERTY(BlueprintReadWrite, Category = "Properties")
		/*This variable is for when you can shoot or not*/
		bool bCanShoot = true;
	/* Handle to manage the timer */
	FTimerHandle FuzeTimerHandle;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Properties")
		UStaticMeshComponent* staticMeshComponent;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "AGun")
		void Shoot();

	UFUNCTION()
		void SetbCanShoot(bool b);

};
