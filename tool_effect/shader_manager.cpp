#include "shader_manager.h"
#include "application.h"
#include "renderer.h"
#include "file.h"
#include "utility.h"

//��������������������������������������������������������������
// �V�F�[�_�[�}�l�[�W���̃R���X�g���N�^
//��������������������������������������������������������������
CShaderManager::CShaderManager() : m_vtxDecl(nullptr)
{
	LPDIRECT3DDEVICE9 pDevice = CApplication::GetInstance()->GetRenderer()->GetDevice();

	// ���_�錾�I�u�W�F�N�g
	m_decl.push_back({ 0 , 0, D3DDECLTYPE_FLOAT3, D3DDECLMETHOD_DEFAULT, D3DDECLUSAGE_POSITION, 0 });	// pos
	m_decl.push_back({ 0, 12, D3DDECLTYPE_FLOAT3, D3DDECLMETHOD_DEFAULT, D3DDECLUSAGE_NORMAL, 0 });		// nor
	m_decl.push_back({ 0, 24, D3DDECLTYPE_D3DCOLOR, D3DDECLMETHOD_DEFAULT, D3DDECLUSAGE_COLOR, 0 });	// col
	m_decl.push_back({ 0, 28, D3DDECLTYPE_FLOAT2, D3DDECLMETHOD_DEFAULT, D3DDECLUSAGE_TEXCOORD, 0 });	// tex
	m_decl.push_back(D3DDECL_END());

	// ���_�錾�I�u�W�F�N�g�̐���
	pDevice->CreateVertexDeclaration(m_decl.data(), &m_vtxDecl);
}

//��������������������������������������������������������������
// �V�F�[�_�[�}�l�[�W���̃f�X�g���N�^
//��������������������������������������������������������������
CShaderManager::~CShaderManager()
{
}

//��������������������������������������������������������������
// �G�t�F�N�g�A�n���h���̓ǂݍ���
//��������������������������������������������������������������
void CShaderManager::Load(nlohmann::json& list)
{
	LPDIRECT3DDEVICE9 pDevice = CApplication::GetInstance()->GetRenderer()->GetDevice();
	LPD3DXBUFFER errorBuffer = nullptr;
	std::string label = list["Label"];
	std::string path = list["Path"];

	// �G�t�F�N�g�t�@�C���̓ǂݍ���
	LPD3DXEFFECT effect = nullptr;
	if (FAILED(D3DXCreateEffectFromFile(pDevice,
		_T(path.c_str()),
		nullptr,
		nullptr,
		0,
		nullptr,
		&effect,
		&errorBuffer)))
	{
		if (errorBuffer != nullptr)
		{
			const char* errorMessage = static_cast<const char*>(errorBuffer->GetBufferPointer());
			MessageBox(CApplication::GetInstance()->GetWindow(), errorMessage, "�x���I", MB_ICONWARNING);
			errorBuffer->Release(); // ���\�[�X�̉��
		}

		assert(false);
	}

	m_effect.insert(std::make_pair(label, effect));

	// �e�N�j�b�N�̃n���h����ۑ�
	size_t techniqueSize = list["Technique"].size();
	for (size_t i = 0; i < techniqueSize; i++)
	{
		std::string techName = "Technique" + std::to_string(i);
		AddTechniqueCache(label, list["Technique"][techName]);
	}

	// �p�����[�^�̃n���h����ۑ�
	size_t parameterSize = list["Parameter"].size();
	for (size_t i = 0; i < parameterSize; i++)
	{
		std::string paramName = "Parameter" + std::to_string(i);
		AddParameterCache(label, list["Parameter"][paramName]);
	}
}

//��������������������������������������������������������������
// Json����V�F�[�_�[���g�p���邽�߂̏��̓ǂݎ��
//��������������������������������������������������������������
void CShaderManager::LoadAll()
{
	nlohmann::json list = CFile::LoadJsonStage(L"Data/FILE/shader.json");

	size_t size = list["SHADER"].size();
	for (size_t i = 0; i < size; i++)
	{
		Load(list["SHADER"].at(i));
	}
}

//��������������������������������������������������������������
// �V�F�[�_�[�}�l�[�W���̔j��
//��������������������������������������������������������������
void CShaderManager::ReleaseAll()
{
	for (auto &p : m_effect)
	{
		if (p.second != nullptr)
		{
			p.second->Release();
		}
	}
	m_effect.clear();

	// ���_�錾�I�u�W�F�N�g�̔j��
	if (!m_decl.empty())
	{
		m_decl.clear();
	}

	if (m_vtxDecl != nullptr)
	{
		m_vtxDecl->Release();
		m_vtxDecl = nullptr;
	}
}

//��������������������������������������������������������������
// �V�F�[�_�[�̓K�p����
//��������������������������������������������������������������
void CShaderManager::Apply(std::string label)
{
	LPDIRECT3DDEVICE9 pDevice = CApplication::GetInstance()->GetRenderer()->GetDevice();
	LPD3DXEFFECT pShader = m_effect[label];
	if (pShader != nullptr)
	{
		pShader->Begin(NULL, 0);
		pShader->BeginPass(0);
	}
}

//��������������������������������������������������������������
// �V�F�[�_�[�̏I������
//��������������������������������������������������������������
void CShaderManager::End(std::string label)
{
	LPDIRECT3DDEVICE9 pDevice = CApplication::GetInstance()->GetRenderer()->GetDevice();
	LPD3DXEFFECT pShader = m_effect[label];
	if (pShader != nullptr)
	{
		pShader->EndPass();
		pShader->End();
	}

	// �Œ�@�\�p�C�v���C���ɖ߂�
	pDevice->SetVertexShader(NULL);
	pDevice->SetPixelShader(NULL);
}

//��������������������������������������������������������������
// �e�N�j�b�N�̃L���b�V���ɗv�f��ǉ�
//��������������������������������������������������������������
void CShaderManager::AddTechniqueCache(const std::string& label, const std::string& handleName)
{
	std::string key = label + "_" + handleName;

	if (m_techniqueCache.count(key) > 0)
	{
		assert(false);
	}
	m_techniqueCache[key] = m_effect[label]->GetTechniqueByName(handleName.c_str());
}

//��������������������������������������������������������������
// �p�����[�^�̃L���b�V���ɗv�f��ǉ�
//��������������������������������������������������������������
void CShaderManager::AddParameterCache(const std::string& label, const std::string& handleName)
{
	std::string key = label + "_" + handleName;

	if (m_parameterCache.count(key) > 0)
	{
		assert(false);
	}
	m_parameterCache[key] = m_effect[label]->GetParameterByName(NULL, handleName.c_str());
}

//��������������������������������������������������������������
// �e�N�j�b�N�̃L���b�V�����擾
//��������������������������������������������������������������
D3DXHANDLE CShaderManager::GetTechniqueCache(const std::string& label, const std::string& handleName)
{
	std::string key = label + "_" + handleName;

	// �L���b�V������n���h�����擾
	if (m_techniqueCache.count(key) < 0)
	{
		return nullptr;
	}
	return m_techniqueCache[key];
}

//��������������������������������������������������������������
// �p�����[�^�̃L���b�V�����擾
//��������������������������������������������������������������
D3DXHANDLE CShaderManager::GetParameterCache(const std::string& label, const std::string& handleName)
{
	std::string key = label + "_" + handleName;

	// �L���b�V������n���h�����擾
	if (m_parameterCache.count(key) < 0)
	{
		return nullptr;
	}
	return m_parameterCache[key];
}