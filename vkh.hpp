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
