#pragma once

#include "GFXProxy.h"
#include "GFXDeviceThread.h"
#include "../gfx/GFXDevice.h"

namespace cc {
namespace gfx {

class CC_DLL DeviceProxy : public Proxy<Device> {
public:
    using Proxy::Proxy;
    using Device::createCommandBuffer;
    using Device::createFence;
    using Device::createQueue;
    using Device::createBuffer;
    using Device::createTexture;
    using Device::createSampler;
    using Device::createShader;
    using Device::createInputAssembler;
    using Device::createRenderPass;
    using Device::createFramebuffer;
    using Device::createDescriptorSet;
    using Device::createDescriptorSetLayout;
    using Device::createPipelineLayout;
    using Device::createPipelineState;
    using Device::copyBuffersToTexture;

    virtual bool initialize(const DeviceInfo &info) override;
    virtual void destroy() override;
    virtual void resize(uint width, uint height) override;
    virtual void acquire() override;
    virtual void present() override;

    virtual CommandBuffer *createCommandBuffer() override;
    virtual Fence *createFence() override;
    virtual Queue *createQueue() override;
    virtual Buffer *createBuffer() override;
    virtual Texture *createTexture() override;
    virtual Sampler *createSampler() override;
    virtual Shader *createShader() override;
    virtual InputAssembler *createInputAssembler() override;
    virtual RenderPass *createRenderPass() override;
    virtual Framebuffer *createFramebuffer() override;
    virtual DescriptorSet *createDescriptorSet() override;
    virtual DescriptorSetLayout *createDescriptorSetLayout() override;
    virtual PipelineLayout *createPipelineLayout() override;
    virtual PipelineState *createPipelineState() override;
    virtual void copyBuffersToTexture(const uint8_t *const *buffers, Texture *dst, const BufferTextureCopy *regions, uint count) override;

    virtual SurfaceTransform getSurfaceTransform() const override { return _remote->getSurfaceTransform(); }
    virtual uint getWidth() const override { return _remote->getWidth(); }
    virtual uint getHeight() const override { return _remote->getHeight(); }
    virtual uint getNativeWidth() const override { return _remote->getNativeWidth(); }
    virtual uint getNativeHeight() const override { return _remote->getNativeHeight(); }
    virtual MemoryStatus &getMemoryStatus() override { return _remote->getMemoryStatus(); }
    virtual uint getNumDrawCalls() const override { return _remote->getNumDrawCalls(); }
    virtual uint getNumInstances() const override { return _remote->getNumInstances(); }
    virtual uint getNumTris() const override { return _remote->getNumTris(); }

    DeviceThread *getDeviceThread() const { return _thread.get(); }

protected:

    friend class DeviceThread;

    std::unique_ptr<DeviceThread> _thread{};
};

} // namespace gfx
} // namespace cc
