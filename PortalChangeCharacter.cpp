// Fill out your copyright notice in the Description page of Project Settings.


#include "PortalChangeCharacter.h"
#include "Components/StaticMeshComponent.h"
#include "Components/SphereComponent.h"
#include "TS_GABRIEL_CABRERACharacter.h"

// Sets default values
APortalChangeCharacter::APortalChangeCharacter()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	Mesh->SetupAttachment(RootComponent);

	Sphere = CreateDefaultSubobject<USphereComponent>(TEXT("Sphere"));
	Sphere->SetupAttachment(Mesh);
	Sphere->SetCollisionResponseToChannels(ECollisionResponse::ECR_Overlap);

	
}

// Called when the game starts or when spawned
void APortalChangeCharacter::BeginPlay()
{
	Super::BeginPlay();
	Sphere->OnComponentBeginOverlap.AddDynamic(this, &APortalChangeCharacter::MyBeginOverlap);

}

// Called every frame
void APortalChangeCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void APortalChangeCharacter::MyBeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	ATS_GABRIEL_CABRERACharacter* player = Cast<ATS_GABRIEL_CABRERACharacter>(OtherActor);
	if (player->IsValidLowLevel())
	{
		player->ChangeMesh();
		
	}
}