// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PortalChangeCharacter.generated.h"

UCLASS()
class TS_GABRIEL_CABRERA_API APortalChangeCharacter : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APortalChangeCharacter();


	UPROPERTY(EditAnywhere, Category = "Properties")
		class UStaticMeshComponent* Mesh;

	UPROPERTY(EditAnywhere, Category = "Properties")
		class USphereComponent* Sphere;

	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION()
		void MyBeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

};
