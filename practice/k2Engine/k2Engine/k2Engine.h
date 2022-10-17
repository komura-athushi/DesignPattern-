#pragma once


namespace nsK2Engine {
#ifdef K2_DEBUG
	namespace nsDbg {
		class VectorRenderer;
	}
#endif // #ifdef K2_DEBUG
	/// <summary>
	/// K2Engine
	/// </summary>
	/// <remark>
	/// 河原学園内製のゲームエンジン。
	/// k2EngineLowをベースに拡張されたエンジンです。
	/// 主に、レンダリングエンジンの機能を提供しています。
	/// 
	/// このクラスはシングルトンパターンで設計されています。
	/// シングルトンパターンは下記の二つの機能を提供するパターンです。
	/// 1.　グローバルなアクセスポイント
	///		->グローバル変数の機能
	/// 2　インスタンスの数を一つに制限する機能。
	/// インスタンスの生成はCreateInstance()、
	/// インスタンスの破棄はDeleteInstance()、
	/// インスタンスの取得はCreateInstance()を呼び出してください。
	/// </reramk>
	class K2Engine {
	private:
		/// <summary>
		/// コンストラクタ。
		/// </summary>
		
		K2Engine(){}
		/// <summary>
		/// デストラクタ。
		/// </summary>
		~K2Engine();
	public:
		/// <summary>
		/// 初期化データ。
		/// </summary>
		struct InitData {
			HWND hwnd;					// ウィンドウハンドル。
			UINT frameBufferWidth;		// フレームバッファの幅。
			UINT frameBufferHeight;		// フレームバッファの高さ。
			bool isSoftShadow;			// ソフトシャドウを行う？
		};
		/// <summary>
		/// インスタンスの作成。
		/// </summary>
		static void CreateInstance(const InitData& initData)
		{
			m_instance = new K2Engine;
			m_instance->Init(initData);
		}
		/// <summary>
		/// インスタンスの破棄。
		/// </summary>
		static void DeleteInstance()
		{
			delete m_instance;
		}
		/// <summary>
		/// インスタンスを取得。
		/// </summary>
		/// <returns></returns>
		static K2Engine* GetInstance()
		{
			return m_instance;
		}
		/// <summary>
		/// K2Engineを初期化
		/// </summary>
		void Init(const InitData& initData);
		/// <summary>
		/// エンジンの処理を実行。
		/// </summary>
		void Execute();
#ifdef K2_DEBUG
		/// <summary>
		/// ベクトルのデバッグ出力
		/// </summary>
		/// <param name="vector">ベクトル</param>
		/// <param name="origin">起点</param>
		/// <param name="name">名前</param>
		void DrawVector(const Vector3& vector, const Vector3& origin, const char* name = "no name");
		/// <summary>
		/// ベクトルのデバッグ描画を有効にする。
		/// </summary>
		void SetDrawVectorEnable();
		/// <summary>
		/// ベクトルのデバッグ描画を無効にする。
		/// </summary>
		void SetDrawVectorDisable();
		/// <summary>
		/// ゲームの開始処理。
		/// </summary>
		void Start()
		{
			g_engine->BeginFrame();
		}
		/// <summary>
		/// ゲームの更新処理。
		/// </summary>
		void Update()
		{
			auto& renderContext = g_graphicsEngine->GetRenderContext();
			g_engine->ExecuteUpdate();
			// レンダリングエンジンの更新。
			m_renderingEngine.Update();
		}
		/// <summary>
		/// 描画処理。
		/// </summary>
		void Render()
		{
			auto& renderContext = g_graphicsEngine->GetRenderContext();

			g_engine->ExecuteRender();
			//レンダリングエンジンを実行。		
			m_renderingEngine.Execute(renderContext);

			//当たり判定描画。
			g_engine->DebubDrawWorld();

			//////////////////////////////////////
			//絵を描くコードを書くのはここまで！！！
			//////////////////////////////////////
			g_engine->EndFrame();
		}
		void End()
		{
			g_engine->End();
		}
#else
		void DrawVector(const Vector3& vector, const Vector3& origin, const char* name = "no name")
		{

		}
		void SetDrawVectorEnable()
		{

		}
		void SetDrawVectorDisable()
		{

		}
#endif // #ifdef K2_DEBUG
	private:

		K2EngineLow m_k2EngineLow;							// 
		CollisionObjectManager m_collisionObjectManager;	// 
		RenderingEngine m_renderingEngine;					// レンダリングエンジン。
#ifdef K2_DEBUG
		nsDbg::VectorRenderer* m_vectorRenderer = nullptr;	// デバッグベクトル描画処理
#endif // K2_DEBUG
		static K2Engine* m_instance;
	};

	// グローバルなアクセスポイント。
	extern K2Engine* g_k2Engine;
	extern RenderingEngine* g_renderingEngine;
	extern SceneLight* g_sceneLight;
	extern CollisionObjectManager* g_collisionObjectManager;

}