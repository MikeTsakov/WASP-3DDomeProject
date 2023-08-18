// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Source/Public/DataHolders.h"
#include "Actors.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnActorDataChanged, const FActorData&, FNewStruct);

UCLASS()
class NDISPLAYDOME_API AActors : public AActor
{
	GENERATED_BODY()

public:	
	// Sets default values for this actor's properties
	AActors();

	FTransform GetTransform();

	void SetTransform(const FTransform* NewTransform);
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FActorData MyStructData;
	
	UPROPERTY(BlueprintAssignable)
	FOnActorDataChanged OnMyStructChanged;

private:
	FActorData LastKnownStructData;
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	void Initialize();

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	USkeletalMeshComponent* SkeletalMeshComponent;

	UPROPERTY()
	TArray<ACharacter*> CharacterActors;
	
	UPROPERTY(EditAnywhere, Category = "Setup")
	FTransform CharacterTransform;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FName CharacterTag;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FName CharacterMesh;
};