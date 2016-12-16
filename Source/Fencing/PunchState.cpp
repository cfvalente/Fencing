// Fill out your copyright notice in the Description page of Project Settings.

#include "Fencing.h"
#include "Vegeta.h"
#include "PunchState.h"

UAnimationAsset *PunchState::AnimationAsset = NULL;


void PunchState::Enter()
{
	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Blue, "Punch");
	Vegeta->GetMesh()->PlayAnimation(AnimationAsset, true);
}
void PunchState::Update()
{
	for (auto it = Vegeta->GetMesh()->AnimScriptInstance->NotifyQueue.AnimNotifies.CreateIterator(); it; ++it)
	{
		if ((*it)->NotifyName.ToString() == "VegetaAnimEnd")
		{
			VegetaState *NewState;
			NewState = StateFactory::CreateAttackIdle(Vegeta);
			Vegeta->GetMesh()->Stop();
			NewState->Enter();
			Vegeta->SetState(NewState);
		}
		if ((*it)->NotifyName.ToString() == "VegetaActiveFrames")
		{
			if (Vegeta->Enemy != NULL)
			{
				//Dano
				if (!Vegeta->Enemy->IsStateActive())
				{
					/* Ideia 1 */
					//Som da porrada
					//Particulas da porrada
					//O dano é calculado na classe inimiga
					//Pode haver problema com os frames --> Codigo foi processado aqui, mas la ainda nao, o active frame pode mudar no meio do caminho e o sistema vai ficar num estado "estranho"
					/* Ideia 2 */
					// Som da Porrada
					// Particulas da porrada
					// Dano calculado aqui e setado na classe inimiga
					// Mudanca de estado para a classe inimiga
					// Meio que derrota o encapsulamento de OO
					// Vai funcionar, mas vai ter repeticao de codigo em varios lugares, simplesmente uma bosta
					// Solucao? --> Sincronizar os estados, como?! 2 ticks? --> Calcular o active frame "agora" e nao deixar numa variavel -- solucao abaixo
				}
				else switch (Vegeta->Enemy->GetState())
				{
					case EVegetaState::Block:
						break;
					case EVegetaState::Reversal:
						break;
				}
			}
		}
	}

}
void PunchState::SetAnimation(UAnimationAsset *AnimationAsset_)
{
	AnimationAsset = AnimationAsset_;
}
bool PunchState::IsActive()
{
	for (auto it = Vegeta->GetMesh()->AnimScriptInstance->NotifyQueue.AnimNotifies.CreateIterator(); it; ++it)
	{
		if ((*it)->NotifyName.ToString() == "VegetaActiveFrames")
		{
			return true;
		}
	}
	return false;
}
PunchState::~PunchState()
{
}
