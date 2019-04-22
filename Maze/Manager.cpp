#include "Manager.hpp"



/// --------------------------------------------------------------------------------------------------
void Manager::SceneChange()
{
	// ���̃V�[��
	switch (BASICPARAM::e_nowScene)
	{
		// �^�C�g��
	case ESceneNumber::TITLE:
		POINTER_RELEASE(p_baseMove);
		p_baseMove = new Title();
		p_baseMove->SetScene(BASICPARAM::e_nowScene);
		break;


		// �Q�[��
	case ESceneNumber::GAME:
		POINTER_RELEASE(p_baseMove);
		p_baseMove = new Game();
		p_baseMove->SetScene(BASICPARAM::e_nowScene);
		break;


	default:
		break;
	}
}



/// --------------------------------------------------------------------------------------------------
Manager::Manager()
{
	// ������
	BASICPARAM::e_preScene = ESceneNumber::TITLE;
	BASICPARAM::e_nowScene = ESceneNumber::TITLE;


	// �������̏�����
	p_baseMove = nullptr;
	p_baseMove = new Title();


	// �Q�[���Ɋւ���
	gameEnd = false;
}



/// --------------------------------------------------------------------------------------------------
Manager::~Manager()
{
	POINTER_RELEASE(p_baseMove);
}



/// --------------------------------------------------------------------------------------------------
void Manager::Update()
{
	// ���̃V�[���ƒ��O�̃V�[��������
	if (BASICPARAM::e_nowScene == BASICPARAM::e_preScene)
	{
		// �Q�[���Ɋւ���
		p_baseMove->Draw();


		// �Q�[���Ɋւ���
		p_baseMove->Process();


		// ���O�̃V�[���ƍ��̃V�[���𓯂��ɂ���
		BASICPARAM::e_nowScene = p_baseMove->GetScene();
	}
	// �V�[�����ڍs����悤�Ɏw�肳�ꂽ��
	else
	{
		// �V�[����ς���
		SceneChange();


		// ���O�̃V�[���ƍ��̃V�[���𓯂��ɂ���
		BASICPARAM::e_preScene = BASICPARAM::e_nowScene;
	}
}