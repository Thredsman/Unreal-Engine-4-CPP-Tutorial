// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Components/StaticMeshComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "Particles/ParticleSystemComponent.h"
#include "BasePlayer.generated.h"

UCLASS()
class COINCOLLECTOR_API ABasePlayer : public APawn
{
	GENERATED_BODY()

public:

	UPROPERTY( VisibleAnywhere, BlueprintReadOnly )
	UStaticMeshComponent* m_Mesh;

	UPROPERTY( VisibleAnywhere, BlueprintReadOnly )
	USpringArmComponent* m_SpringArm;

	UPROPERTY( VisibleAnywhere,BlueprintReadOnly )
	UCameraComponent* m_Camera;

	UPROPERTY( VisibleAnywhere, BlueprintReadOnly )
	UParticleSystemComponent* m_Particles;

	UPROPERTY( EditAnywhere, BlueprintReadWrite )
	float m_MovementForce;

	UPROPERTY( EditAnywhere, BlueprintReadWrite )
	float m_JumpImpulse;

public:
	// Sets default values for this pawn's properties
	ABasePlayer();

	void moveUp(float Value);
	void moveRight(float Value);

	UFUNCTION(BlueprintImplementableEvent)
	void jump();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
