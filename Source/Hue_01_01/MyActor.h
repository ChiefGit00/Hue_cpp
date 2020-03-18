 
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyActor.generated.h"

UCLASS()
class HUE_01_01_API AMyActor : public AActor
{
	GENERATED_BODY()
	
public:	
	AMyActor();

	UPROPERTY(EditAnywhere, Category="Damage")
		int32 TotalDamage;

	

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(VisibleAnywhere)
		UStaticMeshComponent* StaticMesh;
};
