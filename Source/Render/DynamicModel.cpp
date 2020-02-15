#include "DynamicModel.h"
#include "NormalTable.h"
#include "Md2Loader.h"
#include "MdxLoader.h"

namespace Freeking
{
	void DynamicModelLibrary::UpdateLoaders()
	{
		AddLoader<MD2Loader>();
		AddLoader<MDXLoader>();
	}

	DynamicModelLibrary DynamicModel::Library;

	const std::unique_ptr<TextureBuffer>& DynamicModel::GetNormalBuffer()
	{
		static auto normalBuffer = std::make_unique<TextureBuffer>((void*)&NormalTable[0][0], (162 * 3) * sizeof(float), GL_RGB32F);
		return normalBuffer;
	}

	void DynamicModel::Draw()
	{
		_vertexBinding->Bind();
		glDrawElements(GL_TRIANGLES, _vertexBinding->GetNumElements(), GL_UNSIGNED_INT, (void*)0);
		_vertexBinding->Unbind();
	}

	void DynamicModel::Commit()
	{
		static const int vertexSize = sizeof(Vertex);

		_indexBuffer = std::make_unique<IndexBuffer>(Indices.data(), Indices.size(), GL_UNSIGNED_INT);
		_vertexBuffer = std::make_unique<VertexBuffer>(Vertices.data(), Vertices.size(), vertexSize, GL_STATIC_DRAW);
		_frameVertexBuffer = std::make_unique<TextureBuffer>(FrameVertices.data(), FrameVertices.size() * sizeof(FrameVertex), GL_RGBA8I);

		ArrayElement vertexLayout[] =
		{
			ArrayElement(_vertexBuffer.get(), 0, 2, ElementType::Float, vertexSize, 0),
			ArrayElement(_vertexBuffer.get(), 1, 1, ElementType::Int, vertexSize, 2 * sizeof(float)),
		};

		_vertexBinding = std::make_unique<VertexBinding>();
		_vertexBinding->Create(vertexLayout, 2, *_indexBuffer, ElementType::UInt);
	}

	std::vector<FrameAnimation> DynamicModel::GetFrameAnimations() const
	{
		std::vector<FrameAnimation> animations;

		std::string currentFrameName = "";
		size_t currentFrameIndex = 0;

		for (auto frameTransform : FrameTransforms)
		{
			auto indexStart = frameTransform.name.find_last_of('_');
			auto frameName = frameTransform.name.substr(0, indexStart);

			if (currentFrameName != frameName)
			{
				currentFrameName = frameName;
				animations.push_back({ frameName, currentFrameIndex, 0 });
			}

			auto& animFrameIndex = animations.back();
			animFrameIndex.numFrames += 1;

			currentFrameIndex++;
		}

		return animations;
	}
}
