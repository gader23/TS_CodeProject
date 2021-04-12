// Fill out your copyright notice in the Description page of Project Settings.


#include "Dummie.h"
#include "Components/StaticMeshComponent.h"
#include "TimerManager.h"
#include "Components/DecalComponent.h"

// Sets default values
ADummie::ADummie()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	Mesh->SetupAttachment(RootComponent);

	DecalComponent = CreateDefaultSubobject<UDecalComponent>(TEXT("DecalComponent"));
	DecalComponent->SetupAttachment(Mesh);
}

// Called when the game starts or when spawned
void ADummie::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ADummie::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ADummie::SetRotation(float r)
{
	SetActorRotation(FRotator(r, GetActorRotation().Vector().Y, GetActorRotation().Vector().Z));
	if (bIsHit)
	{
		FTimerDelegate TimerDelegate;
		TimerDelegate.BindUFunction(this, FName("SetRotation"), 0.f);
		float rand= FMath::RandRange(2.f, 5.f);
		GetWorld()->GetTimerManager().SetTimer(FuzeTimerHandle, TimerDelegate, rand, false);
		bIsHit = false;
	}
	else
	{
		GetWorldTimerManager().ClearTimer(FuzeTimerHandle);
	}
}

