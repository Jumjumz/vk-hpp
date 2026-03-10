#ifndef VKH_HPP
#define VKH_HPP

#pragma once

#include <vector>
#include <vulkan/vulkan_raii.hpp>

struct VulkanResources {
    // core
    vk::raii::Context context;
    vk::raii::Instance instance = nullptr;
    vk::raii::SurfaceKHR surface_khr = nullptr;

    // devices
    vk::raii::PhysicalDevice physical_device = nullptr;
    vk::raii::Device logical_device = nullptr;

    // queue
    vk::raii::Queue graphics_queue = nullptr;
    vk::raii::Queue present_queue = nullptr;

    // swapchain
    vk::raii::SwapchainKHR swapchain_khr = nullptr;

    // shader module
    vk::raii::ShaderModule shader_module = nullptr;

    // pipeline
    vk::raii::Pipeline graphics_pipeline = nullptr;
    vk::raii::PipelineLayout pipeline_layout = nullptr;

    // layout
    vk::raii::DescriptorSetLayout descriptor_set_layout = nullptr;

    // command pool
    vk::raii::CommandPool command_pool = nullptr;

    // buffers
    vk::raii::Buffer vertex_buffer = nullptr;
    vk::raii::DeviceMemory vertex_memory = nullptr;
    vk::raii::Buffer index_buffer = nullptr;
    vk::raii::DeviceMemory index_memory = nullptr;

    std::vector<vk::raii::Buffer> uniform_buffers;
    std::vector<vk::raii::DeviceMemory> uniform_memories;
    std::vector<void *> uniform_buffers_mapped;

    // image
    vk::raii::Image depth_image = nullptr;
    vk::raii::DeviceMemory depth_memory = nullptr;
    vk::raii::ImageView depth_image_view = nullptr;

    // commands
    std::vector<vk::raii::CommandBuffer> command_buffers;
    std::vector<vk::raii::Semaphore> available_semaphores;
    std::vector<vk::raii::Semaphore> finished_semaphores;
    std::vector<vk::raii::Fence> inflight_fences;

    // descriptor pool
    vk::raii::DescriptorPool descriptor_pool = nullptr;

    std::vector<vk::raii::DescriptorSets> descriptor_sets;

    // validation layer
    const std::vector<char const *> validation_layers = {
        "VK_LAYER_KHRONOS_validation"};

#ifdef NDEBUG
    static constexpr bool enable_validation_layers = false;
#else
    static constexpr bool enable_validation_layers = true;
#endif
};

#endif // !VKH_HPP
