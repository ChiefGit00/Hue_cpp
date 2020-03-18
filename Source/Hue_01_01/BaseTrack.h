#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BaseTrack.generated.h"

UCLASS()
class HUE_01_01_API ABaseTrack : public AActor
{
	GENERATED_BODY()
	
public:	
	ABaseTrack();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Default")
		class UStaticMeshComponent* StaticMesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Default")
		class UChildActorComponent* ChildActor;
};
