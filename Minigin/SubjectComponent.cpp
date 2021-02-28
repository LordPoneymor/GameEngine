#include "MiniginPCH.h"
#include "SubjectComponent.h"

using namespace dae;

SubjectComponent::~SubjectComponent()
{
	for (auto pObs : m_pObservers)
	{
		delete pObs;
	}
}

void SubjectComponent::AddObserver(Observer* pObserver)
{
	if (m_NbrObservers < MAX_OBSERVERS)
	{
		m_pObservers[m_NbrObservers] = pObserver;
		m_NbrObservers++;
	}
}

void SubjectComponent::RemoveObserver(Observer* pObserver)
{
	int toRemoveIndex{};
	for (unsigned int i = 0; i < m_NbrObservers; i++)
	{
		if (m_pObservers[i]==pObserver)
		{
			delete pObserver;
			pObserver = nullptr;
			toRemoveIndex = i;
			break;
		}
	}
	ShiftArray(toRemoveIndex + 1);
}

void SubjectComponent::Notify(SceneObject const& object, Event event)
{
	for (unsigned int i = 0; i < m_NbrObservers; i++)
	{
		m_pObservers[i]->Notify(object, event);
	}
}

void SubjectComponent::ShiftArray(int startIndex)
{
	for (unsigned int i = startIndex; i < m_NbrObservers; i++)
	{
		m_pObservers[i - 1] = m_pObservers[i];
	}
	m_pObservers[m_NbrObservers - 1] = nullptr;
}
