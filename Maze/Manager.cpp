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
		for (int i = 0; i != std::extent<decltype(tempMap), 0>::value; ++i)
		{
			tempMap[i] = map[i];
		}
		p_baseMove = new Title(tempMap);
		p_baseMove->SetScene(BASICPARAM::e_nowScene);
		break;


		// �Q�[��
	case ESceneNumber::GAME:
		POINTER_RELEASE(p_baseMove);
		for (int i = 0; i != std::extent<decltype(tempMap), 0>::value; ++i)
		{
			tempMap[i] = map[i];
		}
		p_baseMove = new Game(tempMap);
		p_baseMove->SetScene(BASICPARAM::e_nowScene);
		break;


		// �G���f�B���O
	case ESceneNumber::END:
		POINTER_RELEASE(p_baseMove);
		for (int i = 0; i != std::extent<decltype(map), 0>::value; ++i)
		{
			for (int j = 0; j != std::extent<decltype(map), 1>::value; ++j)
			{
				map[i][j] = -1;
			}
		}
		p_baseMove = new End();
		p_baseMove->SetScene(BASICPARAM::e_nowScene);


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


	// �}�b�v������
	for (int i = 0; i != std::extent<decltype(map), 0>::value; ++i)
	{
		for (int j = 0; j != std::extent<decltype(map), 1>::value; ++j)
		{
			map[i][j] = -1;
		}
	}
	map[0][0] = static_cast<int>(MAPStep::Start);
	map[std::extent<decltype(map), 0>::value - 1][std::extent<decltype(map), 1>::value - 1] = static_cast<int>(MAPStep::Goal);
	for (int i = 0; i != std::extent<decltype(tempMap), 0>::value; ++i)
	{
		tempMap[i] = map[i];
	}


	// �������̏�����
	p_baseMove = nullptr;
	p_baseMove = new Title(tempMap);


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