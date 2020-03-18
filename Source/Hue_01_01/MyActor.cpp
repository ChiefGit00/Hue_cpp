

#include "MyActor.h"

AMyActor::AMyActor()
{
 	
	PrimaryActorTick.bCanEverTick = true;

	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MyStaticMesh"));

}

void AMyActor::BeginPlay()
{
	Super::BeginPlay();
	
}


void AMyActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

