//＝＝＝＝＝＝＝＝＝＝＝＝＝
//Utility.h
//＝＝＝＝＝＝＝＝＝＝＝＝＝
#ifndef _UTILITY_H_
#define _UTILITY_H_

#include <random>
#include <functional>
#include <chrono>

namespace utility
{
	// 0.0f ~ 1.0fの数値を0 ~ 255に変換する処理
	template<typename T>
	inline int Convert256(T value)
	{
		if (std::is_same<T, D3DXCOLOR>::value)
		{
			value.r *= 255.0f;
			value.g *= 255.0f;
			value.b *= 255.0f;
			value.a *= 255.0f;
		}
		else
		{
			value *= 255.0f;
		}
		return static_cast<int>(value);
	}

	// enumからInt型に変換する処理
	template<typename T>
	inline typename std::underlying_type<T>::type EnumToInt(T value)
	{
		return static_cast<typename std::underlying_type<T>::type>(value);
	}

	// Int型からenumに変換する処理
	template <typename T>
	inline T IntToEnum(typename std::underlying_type<T>::type value)
	{
		return static_cast<T>(value);
	}

	// 数値をランダムにする処理
	template<typename T>
	inline T Random(T max, T min)
	{
		std::random_device seed_gen;
		std::mt19937 gen(seed_gen());
		std::uniform_int_distribution<> distribution(0, 32767);
		int randomValue = distribution(gen);
		return ((randomValue * (1.0f / 32767.0f)) * (max - min)) + min;
	}

	// 要素をランダムに取得する処理
	template<typename T>
	inline T RandomElement(const std::vector<T>& element)
	{
		std::random_device seed_gen;
		std::mt19937 gen(seed_gen());
		std::uniform_int_distribution<size_t> distribution(0, element.size() - 1);
		return element[distribution(gen)];
	}

	// 線形補間の処理
	template<typename T>
	inline T Lerp(const T& start, const T& end, float t)
	{
		return start + (end - start) * t;
	}

	// 数値を範囲内に収める処理
	template<typename T>
	inline T Clamp(T val, T minVal, T maxVal)
	{
		return max(minVal, min(maxVal, val));
	}

	// 要素を一意なものにする処理
	template<typename T>
	inline T Unique(std::vector<T>& container)
	{
		container.erase(std::unique(container.begin(), container.end(), container.end()));
	}

	// 重複なく要素を追加する処理
	template<typename T>
	inline void AddUnique(std::vector<T>& container, const T& val)
	{
		if (std::find(container.begin(), container.end(), val) == container.end())
		{
			container.push_back(value);
		}
	}

	// ベクターの全ての要素を文字列にする処理
	template<typename T>
	inline std::string VectorToString(const std::vector<T>& vector)
	{
		std::string result;
		for (const auto& p : vector)
		{
			result += std::to_string(p) + " ";
		}
		return result;
	}

	// 関数の実行時間を計測する処理
	inline long long ExecutionTime(const std::function<void()>& func)
	{
		auto start = std::chrono::high_resolution_clock::now();
		func();
		auto end = std::chrono::high_resolution_clock::now();
		return std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
	}

	// 角度の正規化
	inline float AngleNormalize(float& angle)
	{
		if (angle > D3DX_PI)
		{
			angle = angle - D3DX_PI * 2;
		}
		else if (angle < -D3DX_PI)
		{
			angle = angle + D3DX_PI * 2;
		}

		return angle;
	}

	// 角度の正規化
	inline D3DXVECTOR3 AngleNormalize(D3DXVECTOR3& angle)
	{
		AngleNormalize(angle.x);
		AngleNormalize(angle.y);
		AngleNormalize(angle.z);

		return angle;
	}

	// ２次元ベクトル計算
	inline float Vec2Cross(D3DXVECTOR3* vec1, D3DXVECTOR3* vec2)
	{
		return vec1->x * vec2->z - vec1->z * vec2->x;
	}

	// 2Dベクトルの内積
	inline float Vec2Dot(D3DXVECTOR3* v1, D3DXVECTOR3* v2)
	{
		return v1->x * v2->x + v1->z * v2->z;
	}
};

#endif
