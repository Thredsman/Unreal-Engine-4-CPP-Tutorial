// Fill out your copyright notice in the Description page of Project Settings.


#include "BasePlayer.h"

// Sets default values
ABasePlayer::ABasePlayer()
{
	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	m_Mesh = CreateDefaultSubobject<UStaticMeshComponent>( TEXT( "Mesh" ) );
	m_SpringArm = CreateDefaultSubobject<USpringArmComponent>( TEXT( "SpringArm" ) );
	m_Camera = CreateDefaultSubobject<UCameraComponent>( TEXT( "Camera" ) );
	m_Particles = CreateDefaultSubobject<UParticleSystemComponent>( TEXT( "Particles" ) );

	RootComponent = m_Mesh;
	m_SpringArm->SetupAttachment(m_Mesh);
	m_Camera->SetupAttachment(m_SpringArm);
	m_Particles->SetupAttachment(m_Mesh);

	m_Mesh->SetSimulatePhysics(true);
	m_MovementForce = 100000;
}

// Called to bind functionality to input
void ABasePlayer::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis( "MoveUp", this, &ABasePlayer::moveUp );
	PlayerInputComponent->BindAxis( "MoveRight", this, &ABasePlayer::moveRight );
	
	PlayerInputComponent->BindAction( "Jump", IE_Pressed, this, &ABasePlayer::jump);
}

void ABasePlayer::moveUp( float Value )
{
	FVector ForceToAdd = FVector(1,0,0) * m_MovementForce * Value;
	m_Mesh->AddForce(ForceToAdd);
}

void ABasePlayer::moveRight( float Value )
{
	FVector ForceToAdd = FVector(0,1,0) * m_MovementForce * Value;
	m_Mesh->AddForce(ForceToAdd);
}

// Called when the game starts or when spawned
void ABasePlayer::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ABasePlayer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


